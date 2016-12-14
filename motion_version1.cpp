#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/nman.h>

#include <native/task.h>
#include <native/timer.h>



typedef struct
{
	bool Request;
	bool Response;
	bool Done;
	double Position;
	double Velocity;
	double Acceleration;
	double Deceleration;
	double Jerk;
} tPosCmd;

typedef struct
{
	double Position;
	double Velocity;
} tAxisSetpoint;



RT_TASK task_trajectory_generator;
RT_TASK task_command_sender;

tPosCmd new_cmd;
tAxisSetpoint axis1_setpoint;

int cycle_count = 0;
double t = 0;
double T = 1000 / 50;//f=50Hz, t(ms)


void task_trajectory_generator_proc()
{
	RTIME now, previous;
	previous = rt_timer_read();

	axis1_setpoint.Position = 0;
	axis1_setpoint.Velocity = 0;

	while (1)
	{
		printf("trajectory generator\n");

		if (new_cmd.Request)
		{
			new_cmd.Response = true;

			now = rt_timer_read();
			t += (double)(now - previous) / 1000000;

			if (t <= 20)
			{
				axis1_setpoint.Velocity += new_cmd.Acceleration*T;
				axis1_setpoint.Position += axis1_setpoint.Velocity*T;
			}
			else if (t <= 200)
			{
				axis1_setpoint.Velocity = new_cmd.Velocity;
				axis1_setpoint.Position += axis1_setpoint.Velocity*T;
			}
			else
			{
				axis1_setpoint.Velocity -=new_cmd.Deceleration*T;
				axis1_setpoint.Position += axis1_setpoint.Velocity*T;

				if (axis1_setpoint.Position == new_cmd.Position)
				{
					new_cmd.Done = true;
				}
			}
		}
	}
}

void task_command_sender_proc()
{
	RTIME now, previous;

	/*
	* Arguments: &task (NULL=self),
	*            start time,
	*            period (here: 2 s)
	*/
	rt_task_set_periodic(NULL, TM_NOW, 2000000000);
	previous = rt_timer_read();

	new_cmd.Request = false;
	new_cmd.Response = false;
	new_cmd.Done = false;
	new_cmd.Position = 0;
	new_cmd.Velocity = 0;
	new_cmd.Acceleration = 0;
	new_cmd.Deceleration = 0;
	new_cmd.Jerk = 0;

	while (1) {
		rt_task_wait_period(NULL);
		now = rt_timer_read();
		printf("Task B Time since last turn: %ld.%06ld ms\n",
			(long)(now - previous) / 1000000,
			(long)(now - previous) % 1000000);
		previous = now;
		cycle_count = cycle_count + 1;
		printf("cycle_count:%d\n", cycle_count);

		if (cycle_count == 5)
		{
			new_cmd.Request = true;
			new_cmd.Response = false;
			new_cmd.Done = false;
			new_cmd.Position = 200000;
			new_cmd.Velocity = 1000;
			new_cmd.Acceleration = 50;
			new_cmd.Deceleration = 50;
			new_cmd.Jerk = 0;
		}
	}
}

void catch_signal(int sig)
{

}


int main(int argc, char* argv[])
{
	signal(SIGTERM, catch_signal);
	signal(SIGINT, catch_signal);

	/* Avoids memory swapping for this program */
	mlockall(MCL_CURRENT | MCL_FUTURE);

	printf("A simple motion control demo\n");
	/*
	* Arguments: &task,
	*            name,
	*            stack size (0=default),
	*            priority,
	*            mode (FPU, start suspended, ...)
	*/
	rt_task_create(&task_trajectory_generator, "rttask_trajectory_generator", 0, 98, 0);
	rt_task_create(&task_command_sender, "rttask_command_sender", 0, 99, 0);

	/*
	* Arguments: &task,
	*            task function,
	*            function argument
	*/
	rt_task_start(&task_trajectory_generator, &task_trajectory_generator_proc, NULL);
	rt_task_start(&task_command_sender, &task_command_sender_proc, NULL);

	while (!new_cmd.Done);
	printf("End! \n");
	rt_task_delete(&task_trajectory_generator);
	rt_task_delete(&task_command_sender);
	return 0;
}
