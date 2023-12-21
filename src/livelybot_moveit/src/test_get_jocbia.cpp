#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_state/robot_state.h>
// #include <robot_model_loader.h>
int main(int argc, char** argv)
{
  ros::init(argc, argv, "get_jacobian_example");
  ros::AsyncSpinner spinner(1);
  spinner.start();

  // 加载机器人模型
  robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
  robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();

  // 创建机器人状态
  robot_state::RobotStatePtr kinematic_state(new robot_state::RobotState(kinematic_model));
  kinematic_state->setToDefaultValues();

  // 指定要计算雅可比矩阵的链接和参考点
  const robot_state::JointModelGroup* joint_model_group = kinematic_model->getJointModelGroup("left_leg_force");
  const std::vector<std::string>& joint_names = joint_model_group->getVariableNames();
  const Eigen::Vector3d reference_point_position(0.0, 0.0, 0.0);
  const std::string& link_name = joint_model_group->getLinkModelNames().back(); // 假设我们想要最后一个链接的雅可比矩阵

  // 获取雅可比矩阵
  Eigen::MatrixXd jacobian;
  kinematic_state->getJacobian(joint_model_group,
                               kinematic_state->getLinkModel(link_name),
                               reference_point_position,
                               jacobian);

  // 输出雅可比矩阵
  std::cout << "Jacobian: \n" << jacobian << std::endl;

  ros::shutdown();
  return 0;
}