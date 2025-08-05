<template>
  <el-card>
    <h2>笔记分享</h2>
    <div v-for="note in notes" :key="note.id" style="margin-bottom: 1rem;">
      <el-card shadow="hover">
        <h3>{{ note.title }}</h3>
        <p>{{ note.content }}</p>
        <el-button type="primary" size="small">查看详情</el-button>
      </el-card>
    </div>
  </el-card>
</template>

<script setup>
const notes = [
  { id: 1, title: '算法学习笔记', content: '记录了常用算法模板和思路。' },
  { id: 2, title: '英语单词记忆', content: '分享高效记忆单词的方法。' },
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