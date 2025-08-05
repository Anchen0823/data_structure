<template>
  <el-card shadow="hover">
    <el-tabs v-model="activeTab" @tab-click="onTabClick">
      <el-tab-pane label="笔记撰写" name="note" />
      <el-tab-pane label="笔记分享" name="share" />
    </el-tabs>
    <router-view />
  </el-card>
</template>

<script setup>
import { ref, onMounted, watch } from 'vue';
import { useRouter, useRoute } from 'vue-router';

const router = useRouter();
const route = useRoute();

// 根据当前路由设置活动选项卡
const getActiveTab = () => {
  const path = route.path;
  console.log('SocialPlatform - Current path:', path);
  // 直接返回路径的最后部分
  const tabName = path.substring(1); // 移除开头的 /
  console.log('SocialPlatform - Extracted tab name:', tabName);
  return tabName;
};

const activeTab = ref(getActiveTab());

const onTabClick = (tab) => {
  console.log('SocialPlatform - Tab clicked:', tab.paneName);
  
  // 直接跳转到根路径
  const targetPath = `/${tab.paneName}`;
  console.log('SocialPlatform - Navigating to:', targetPath);
  
  // 使用命名路由导航
  router.push({ name: tab.paneName });
};

// 监听路由变化，更新活动选项卡
watch(() => route.path, (newPath) => {
  console.log('SocialPlatform - Route changed to:', newPath);
  activeTab.value = getActiveTab();
});

onMounted(() => {
  console.log('SocialPlatform mounted, current route:', route.path);
  if (route.path === '/') {
    console.log('SocialPlatform - Redirecting to /note');
    router.replace('/note');
  }
});
</script>

<style scoped>
.el-card {
  min-height: 60vh;
  margin: 2rem auto;
  max-width: 900px;
}
</style> 