// ConfigFile.h

// SPDX-FileCopyrightText: 2022-2023, Yaskawa America, Inc.
// SPDX-FileCopyrightText: 2022-2023, Delft University of Technology
//
// SPDX-License-Identifier: Apache-2.0

#ifndef MOTOROS2_CONFIG_FILE_H
#define MOTOROS2_CONFIG_FILE_H

#include "ControllerStatusIO.h"
#include "motoPlus.h"

// NOTE: We do not prefix joints by the "motoman Grp ID" here, but use the generic
// group & joint names instead to avoid the OEM-specific names.
#define DEFAULT_JOINT_NAME_FMT "group_%d/joint_%d"

typedef struct
{
    // TODO(gavanderhoorn): add support for uns
    char joint_names[MAX_CONTROLLABLE_GROUPS * MP_GRP_AXES_NUM][MAX_JOINT_NAME_LENGTH];

    char inform_job_name[MAX_JOB_NAME_LEN];
} Ros_Configuration_Settings;

extern Ros_Configuration_Settings g_nodeConfigSettings;

#endif // MOTOROS2_CONFIG_FILE_H
