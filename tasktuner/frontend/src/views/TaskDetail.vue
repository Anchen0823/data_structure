<template>
  <div>
    <h2>任务详情</h2>
    <div v-if="task">
      <p><strong>标题：</strong>{{ task.title }}</p>
      <p><strong>描述：</strong>{{ task.description }}</p>
      <!-- 预留更多任务信息展示 -->
    </div>
    <div v-else>
      加载中...
    </div>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue';
import { useRoute } from 'vue-router';
import { fetchTaskDetail } from '../api';

const route = useRoute();
const task = ref(null);

onMounted(() => {
  fetchTaskDetail(route.params.id).then(data => {
    task.value = data;
  });
});
</script> 