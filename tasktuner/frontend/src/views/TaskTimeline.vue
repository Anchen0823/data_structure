<template>
  <el-card>
    <h2>时间分配图谱</h2>
    <el-timeline>
      <el-timeline-item v-for="item in timeline" :key="item.time" :timestamp="item.time" :color="item.color">
        {{ item.content }}
      </el-timeline-item>
    </el-timeline>
  </el-card>
</template>

<script setup>
const timeline = [
  { time: '08:00', content: '起床', color: '#67C23A' },
  { time: '09:00', content: '学习算法', color: '#409EFF' },
  { time: '11:00', content: '休息', color: '#E6A23C' },
  { time: '14:00', content: '写作业', color: '#F56C6C' },
];
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