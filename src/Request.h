/**
 * @file Request.h
 * @brief Defines the Request structure used in the load balancer simulation.
 *
 * A Request represents a client job submitted to the load balancer.
 * Each request contains identifying information and processing details.
 */

#pragma once
#include <cstdint>

/**
 * @struct Request
 * @brief Represents a single web request.
 *
 * A Request contains:
 * - A unique identifier
 * - Source IP address
 * - Destination IP address
 * - Processing duration in clock cycles
 * - Job type (Processing or Streaming)
 */
struct Request {

    uint64_t id;        
    uint32_t ip_in;     
    uint32_t ip_out;    
    int duration;       
    char jobType;       
};