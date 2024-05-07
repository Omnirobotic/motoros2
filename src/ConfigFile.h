// ConfigFile.h

// SPDX-FileCopyrightText: 2022-2023, Yaskawa America, Inc.
// SPDX-FileCopyrightText: 2022-2023, Delft University of Technology
//
// SPDX-License-Identifier: Apache-2.0

#ifndef MOTOROS2_CONFIG_FILE_H
#define MOTOROS2_CONFIG_FILE_H

#include "motoPlus.h"

// NOTE: We do not prefix joints by the "motoman Grp ID" here, but use the generic
// group & joint names instead to avoid the OEM-specific names.
#define DEFAULT_JOINT_NAME_FMT          "group_%d/joint_%d"

typedef struct
{
    //TODO(gavanderhoorn): add support for uns
    // COMOLI
    // MAX_CONTROLLABLE_GROUPS : 8
    // MAX_JOINT_NAME_LENGTH : 32
    char joint_names[8 * MP_GRP_AXES_NUM][32];

    char inform_job_name[MAX_JOB_NAME_LEN];
} Ros_Configuration_Settings;

extern Ros_Configuration_Settings g_nodeConfigSettings;

#endif  // MOTOROS2_CONFIG_FILE_H
