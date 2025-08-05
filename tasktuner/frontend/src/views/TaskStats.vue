<template>
  <el-card>
    <h2>按日统计任务时长</h2>
    <div ref="chartRef" style="height: 300px; width: 100%;"></div>
  </el-card>
</template>

<script setup>
import { onMounted, ref } from 'vue';
let chart = null;
const chartRef = ref(null);
const data = [
  { date: '2024-06-01', duration: 2 },
  { date: '2024-06-02', duration: 1.5 },
  { date: '2024-06-03', duration: 2.5 },
];
onMounted(async () => {
  const echarts = await import('echarts');
  chart = echarts.init(chartRef.value);
  chart.setOption({
    xAxis: { type: 'category', data: data.map(d => d.date) },
    yAxis: { type: 'value' },
    series: [{ type: 'bar', data: data.map(d => d.duration), name: '时长' }],
    tooltip: {},
    legend: { data: ['时长'] },
  });
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