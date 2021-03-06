/*
 * Arm SCP/MCP Software
 * Copyright (c) 2019-2021, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <mod_sensor.h>

#include <fwk_id.h>

#include <stdint.h>

/*!
 * \cond
 */

/*
 * Sensor trip point element context
 */
struct sensor_trip_point_ctx {
    struct mod_sensor_trip_point_params params;
    bool above_threshold;
};

/*
 * Sensor element context
 */
struct sensor_dev_ctx {
    struct mod_sensor_dev_config *config;

    struct mod_sensor_driver_api *driver_api;

    struct sensor_trip_point_ctx *trip_point_ctx;
    uint32_t cookie;
    bool read_busy;
};

struct sensor_mod_ctx {
    struct mod_sensor_config *config;
    struct mod_sensor_trip_point_api *sensor_trip_point_api;
};

/*
 * Sensor event indexes
 */
enum mod_sensor_event_idx {
    SENSOR_EVENT_IDX_READ_REQUEST = MOD_SENSOR_EVENT_IDX_READ_REQUEST,
    SENSOR_EVENT_IDX_READ_COMPLETE,
    SENSOR_EVENT_IDX_COUNT
};

/*
 * Event identifiers
 */
static const fwk_id_t mod_sensor_event_id_read_complete =
    FWK_ID_EVENT_INIT(FWK_MODULE_IDX_SENSOR,
                      SENSOR_EVENT_IDX_READ_COMPLETE);

/*!
 * \endcond
 */

#endif /* SENSOR_H */
