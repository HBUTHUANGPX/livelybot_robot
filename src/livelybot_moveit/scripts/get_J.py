import rospy
import moveit_commander
from moveit_commander import MoveGroupCommander
import numpy.matlib
group_name='left_leg_force'
group=moveit_commander.MoveGroupCommander(group_name)
current_joint_values=group.get_current_joint_values()
joint_name = group.get_active_joints()
print(joint_name)
current_jacobian_matrix=group.get_jacobian_matrix(current_joint_values)
print(current_jacobian_matrix)

