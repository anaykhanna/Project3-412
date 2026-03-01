/**
 * @mainpage Load Balancer Simulation
 *
 * @section intro Introduction
 *
 * This project simulates a dynamic load balancing system that distributes
 * incoming web requests across multiple web servers.
 *
 * @section features Features
 *
 * - Random request generation
 * - Firewall IP range blocking
 * - Dynamic server scaling (50–80 rule)
 * - Cooldown logic to prevent oscillation
 * - Statistics tracking and summary
 *
 * @section design Design Overview
 *
 * The system consists of:
 * - Request struct
 * - RequestQueue class
 * - WebServer class
 * - LoadBalancer class
 * - Firewall class
 *
 * The LoadBalancer dynamically allocates and deallocates servers
 * based on queue size thresholds to maintain system balance.
 */