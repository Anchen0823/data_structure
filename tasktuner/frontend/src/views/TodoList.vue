<template>
  <div>
    <h2>任务列表</h2>
    <ul>
      <li v-for="task in tasks" :key="task.id">
        <router-link :to="`/task/${task.id}`">{{ task.title }}</router-link>
      </li>
    </ul>
    <!-- 预留添加任务表单 -->
    <TaskForm />
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue';
import { fetchTasks } from '../api';
import TaskForm from '../components/TaskForm.vue';

const tasks = ref([]);

onMounted(() => {
  fetchTasks().then(data => {
    tasks.value = data;
  });
});
</script> 