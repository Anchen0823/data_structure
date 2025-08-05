<template>
  <form @submit.prevent="onSubmit">
    <input v-model="title" placeholder="任务标题" required />
    <textarea v-model="description" placeholder="任务描述"></textarea>
    <button type="submit">添加任务</button>
  </form>
</template>

<script setup>
import { ref } from 'vue';
// import { addTask } from '../api'; // 预留

const title = ref('');
const description = ref('');

function onSubmit() {
  // TODO: 调用API添加任务
  // addTask({ title: title.value, description: description.value })
  //   .then(() => { ... });
  alert('预留添加任务功能');
  title.value = '';
  description.value = '';
}
</script> 