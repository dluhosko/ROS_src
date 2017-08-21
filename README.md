# SENSO - SCARA PROJECT

## Part 1 - scara_v2_with_gripper - Rviz kinematic simulation
1. roslaunch scara_v2_with_gripper xacro_display_scara_rt.launch
2. roslaunch scara_v2_with_gripper xacro_display_scara.launch
3. roslaunch scara_v2_with_gripper xacro_display_rotary_table.launch

## Part 2 - scara_and_rt_moveit_config - Moveit! configuration of SCARA
1. roslaunch scara_and_rt_moveit_config demo_rviz.launch
> Run this launchfile for only kinematic simulation (in your local PC)
2. roslaunch scara_and_rt_moveit_config demo_gazebo.launch
> Run this launchfile for kinematic and dynamic simulation (in your local PC)
3. roslaunch scara_and_rt_moveit_config demo_matlab_simulink.launch
> Run this launchfile for simulation via Simulink (not really helpfull)
4. roslaunch scara_and_rt_moveit_config demo_matlab_mfile.launch
> Run this launchfile for simulation via Matlab (PC-Matlab-SLRT-SCARA)
 **Most important launchfile!**

## Part 3 - gazebo_scara_and_rt - Gazebo dynamic simulation
1. **scara_v2_full_description** : Rviz kinematic simulation
- This is used to test the SCARA manipulator (such as part 1), but here are saved the URDF models for Gazebo
2. **scara_v2_full_gazebo** : Gazebo world for SCARA
3. **scara_v2_full_control** : Gazebo controllers
4. **scara_v2_moveit_api** : Source codes for control of SCARA
