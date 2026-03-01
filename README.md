/**
 * @mainpage Load Balancer Simulation
 *
 * @section intro_sec Introduction
 *
 * This project simulates a dynamic load balancer system.
 *
 * Features:
 * - Request generation with random IPs
 * - Firewall IP blocking
 * - Dynamic server scaling (50–80 rule)
 * - Cooldown logic
 * - Statistics tracking
 *
 * @section design_sec Design Overview
 *
 * The system contains:
 * - Request struct
 * - RequestQueue class
 * - WebServer class
 * - LoadBalancer class
 * - Firewall class
 *
 * The LoadBalancer dynamically allocates and deallocates servers
 * based on queue size thresholds.
 *
 */