<template>
  <el-card>
    <h2>任务管理</h2>
    <el-button type="primary" style="margin-bottom: 1rem;">新建任务</el-button>
    <el-table :data="tasks" style="width: 100%">
      <el-table-column prop="name" label="任务名称" />
      <el-table-column prop="date" label="日期" />
      <el-table-column prop="duration" label="时长(小时)" />
      <el-table-column label="操作">
        <template #default="scope">
          <el-button size="small" type="success">编辑</el-button>
          <el-button size="small" type="danger">删除</el-button>
        </template>
      </el-table-column>
    </el-table>
  </el-card>
</template>

<script setup>
import { onMounted } from 'vue';

const tasks = [
  { name: '学习算法', date: '2024-06-01', duration: 2 },
  { name: '写作业', date: '2024-06-02', duration: 1.5 },
];

onMounted(() => {
  console.log('TaskList component mounted');
});
</script>

<style scoped>
h2 {
  margin-bottom: 1rem;
}
.el-card {
  max-width: 700px;
  margin: 0 auto;
}
</style> 