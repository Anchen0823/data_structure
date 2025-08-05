// 任务管理API空壳

export function fetchTasks() {
  // TODO: 调用后端API获取任务列表
  return Promise.resolve([
    { id: 1, title: '示例任务1' },
    { id: 2, title: '示例任务2' }
  ]);
}

export function fetchTaskDetail(id) {
  // TODO: 调用后端API获取任务详情
  return Promise.resolve({
    id,
    title: `示例任务${id}`,
    description: '这里是任务描述（占位）'
  });
}

export function addTask(task) {
  // TODO: 调用后端API添加任务
  return Promise.resolve({ id: Date.now(), ...task });
} 