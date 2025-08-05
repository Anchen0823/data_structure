<template>
  <el-card>
    <h2>笔记撰写</h2>
    <el-form label-width="60px">
      <el-form-item label="标题">
        <el-input v-model="title" placeholder="请输入笔记标题" />
      </el-form-item>
      <el-form-item label="内容">
        <el-input
          v-model="content"
          type="textarea"
          :rows="8"
          placeholder="请输入笔记内容"
        />
      </el-form-item>
      <el-form-item>
        <el-button type="primary">保存</el-button>
      </el-form-item>
    </el-form>
  </el-card>
</template>

<script setup>
import { ref } from 'vue';
const title = ref('');
const content = ref('');
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