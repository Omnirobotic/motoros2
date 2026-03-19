// ConfigFile.c

// SPDX-FileCopyrightText: 2022-2023, Yaskawa America, Inc.
// SPDX-FileCopyrightText: 2022-2023, Delft University of Technology
//
// SPDX-License-Identifier: Apache-2.0

/*
------------------------------------
Example parsing-event sequence
https://github.com/meffie/libyaml-examples (scan.c)
------------------------------------
stream-start-event (1)
 -document-start-event (3)
 - -mapping-start-event (9)
 - - -scalar-event (6) = {value="automatic_agent_discovery", length=25}
 - - -scalar-event (6) = {value="false", length=5}
 - - -scalar-event (6) = {value="agent_ip_address", length=16}
 - - -scalar-event (6) = {value="192.168.1.50", length=12}
 - - -scalar-event (6) = {value="agent_port_number", length=17}
 - - -scalar-event (6) = {value="8888", length=4}
 - - -scalar-event (6) = {value="sync_timeclock_with_agent", length=25}
 - - -scalar-event (6) = {value="true", length=4}
 - - -scalar-event (6) = {value="publish_tf", length=10}
 - - -scalar-event (6) = {value="true", length=4}
 - - -scalar-event (6) = {value="joint_names", length=11}
 - - -sequence-start-event (7)
 - - - -sequence-start-event (7)
 - - - - -scalar-event (6) = {value="group_1/joint_1", length=15}
 - - - - -scalar-event (6) = {value="group_1/joint_2", length=15}
 - - - - -scalar-event (6) = {value="group_1/joint_3", length=15}
 - - - - -scalar-event (6) = {value="group_1/joint_4", length=15}
 - - - - -scalar-event (6) = {value="group_1/joint_5", length=15}
 - - - - -scalar-event (6) = {value="group_1/joint_6", length=15}
 - - - -sequence-end-event (8)
 - - - -sequence-start-event (7)
 - - - - -scalar-event (6) = {value="group_2/joint_1", length=15}
 - - - - -scalar-event (6) = {value="group_2/joint_2", length=15}
 - - - - -scalar-event (6) = {value="group_2/joint_3", length=15}
 - - - - -scalar-event (6) = {value="group_2/joint_4", length=15}
 - - - - -scalar-event (6) = {value="group_2/joint_5", length=15}
 - - - - -scalar-event (6) = {value="group_2/joint_6", length=15}
 - - - -sequence-end-event (8)
 - - -sequence-end-event (8)
 - - -scalar-event (6) = {value="logging", length=7}
 - - -mapping-start-event (9)
 - - - -scalar-event (6) = {value="verbosity", length=9}
 - - - -scalar-event (6) = {value="1", length=1}
 - - - -scalar-event (6) = {value="log_to_stdout", length=13}
 - - - -scalar-event (6) = {value="false", length=5}
 - - -mapping-end-event (10)
 - - -scalar-event (6) = {value="clock_periods", length=11}
 - - -mapping-start-event (9)
 - - - -scalar-event (6) = {value="executor_sleep_period", length=19}
 - - - -scalar-event (6) = {value="10", length=2}
 - - - -scalar-event (6) = {value="action_feedback_publisher_period", length=32}
 - - - -scalar-event (6) = {value="20", length=2}
 - - - -scalar-event (6) = {value="controller_status_monitor_period", length=33}
 - - - -scalar-event (6) = {value="10", length=2}
 - - -mapping-end-event (10)
 - - -scalar-event (6) = {value="publisher_qos", length=13}
 - - -mapping-start-event (9)
 - - - -scalar-event (6) = {value="robot_status", length=12}
 - - - -scalar-event (6) = {value="best_effort", length=11}
 - - - -scalar-event (6) = {value="joint_states", length=12}
 - - - -scalar-event (6) = {value="best_effort", length=11}
 - - - -scalar-event (6) = {value="tf", length=2}
 - - - -scalar-event (6) = {value="reliable", length=8}
 - - -mapping-end-event (10)
 - -mapping-end-event (10)
 -document-end-event (4)
stream-end-event (2)
*/

#include "ConfigFile.h"

Ros_Configuration_Settings g_nodeConfigSettings;
