<template>
  <el-card>
    <h2>日历视图</h2>
    <el-calendar v-model="value" />
  </el-card>
</template>

<script setup>
import { ref, onMounted } from 'vue';

const value = ref(new Date());

onMounted(() => {
  console.log('TaskCalendar component mounted');
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