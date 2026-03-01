Load Balancer Simulation

Overview

This project simulates a dynamic web load balancer in C++.
It distributes incoming requests across multiple web servers while maintaining system stability.

The simulation includes:
	•	Random request generation
	•	Firewall IP blocking (10.x.x.x and 192.168.x.x)
	•	Dynamic server scaling using the 50–80 rule
	•	Cooldown logic to prevent oscillation
	•	Performance statistics summary

⸻

How It Works
	•	Each request contains an ID, source IP, destination IP, duration, and job type.
	•	Each web server processes one request at a time.
	•	The load balancer:
	•	Scales up if queue size > 80 × number of servers
	•	Scales down if queue size < 50 × number of servers
	•	Uses a cooldown period to prevent rapid scaling changes
	•	The firewall blocks requests from specified IP ranges.

At the end of the simulation, the system reports:
	•	Total Generated
	•	Total Processed
	•	Total Blocked
	•	Scale Ups / Scale Downs
	•	Max Queue Size
	•	Average Queue Size
	•	Final Server Count

⸻

Build

make

Clean build files:

make clean

⸻

Run

./loadbalancer  

Example:

./loadbalancer 5 200

Required assignment run:

./loadbalancer 10 10000 > run_log.txt

⸻

Documentation

Doxygen-generated HTML documentation is hosted on people.tamu.edu.

⸻
