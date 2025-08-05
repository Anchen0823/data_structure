<template>
  <el-container id="app">
    <el-header>
      <el-menu :default-active="activeMenu" mode="horizontal" @select="handleMenuSelect">
        <el-menu-item index="task">任务清单管理</el-menu-item>
        <el-menu-item index="social">学习社交平台</el-menu-item>
      </el-menu>
    </el-header>
    <el-main>
      <!-- 任务清单管理的选项卡 -->
      <div v-if="isTaskSection">
        <el-card shadow="hover">
          <el-tabs v-model="activeTab" @tab-click="onTabClick">
            <el-tab-pane label="日历视图" name="calendar" />
            <el-tab-pane label="任务管理" name="list" />
            <el-tab-pane label="时间分配图谱" name="timeline" />
            <el-tab-pane label="按日统计任务时长" name="stats" />
          </el-tabs>
        </el-card>
      </div>
      
      <!-- 学习社交平台的选项卡 -->
      <div v-if="isSocialSection">
        <el-card shadow="hover">
          <el-tabs v-model="activeTab" @tab-click="onTabClick">
            <el-tab-pane label="笔记撰写" name="note" />
            <el-tab-pane label="笔记分享" name="share" />
          </el-tabs>
        </el-card>
      </div>
      
      <!-- 路由视图 -->
      <router-view />
    </el-main>
  </el-container>
</template>

<script setup>
import { ref, watch, computed } from 'vue';
import { useRouter, useRoute } from 'vue-router';
import 'element-plus/dist/index.css';

const router = useRouter();
const route = useRoute();

// 根据当前路由确定活动菜单
const getActiveMenu = () => {
  const path = route.path;
  if (['/calendar', '/list', '/timeline', '/stats'].includes(path)) {
    return 'task';
  } else if (['/note', '/share'].includes(path)) {
    return 'social';
  }
  return 'task'; // 默认
};

const activeMenu = ref(getActiveMenu());

// 计算当前是否在任务部分
const isTaskSection = computed(() => {
  return ['/calendar', '/list', '/timeline', '/stats'].includes(route.path);
});

// 计算当前是否在社交部分
const isSocialSection = computed(() => {
  return ['/note', '/share'].includes(route.path);
});

// 根据当前路由设置活动选项卡
const getActiveTab = () => {
  const path = route.path;
  return path.substring(1); // 移除开头的 /
};

const activeTab = ref(getActiveTab());

const handleMenuSelect = (key) => {
  if (key === 'task') {
    router.push('/calendar');
  } else if (key === 'social') {
    router.push('/note');
  }
  activeMenu.value = key;
};

const onTabClick = (tab) => {
  console.log('Tab clicked:', tab.paneName);
  const targetPath = `/${tab.paneName}`;
  console.log('Navigating to:', targetPath);
  router.push({ name: tab.paneName });
};

// 监听路由变化，更新活动菜单和选项卡
watch(() => route.path, () => {
  activeMenu.value = getActiveMenu();
  activeTab.value = getActiveTab();
});
</script>

<style>
#app {
  min-height: 100vh;
  background: #f6f8fa;
}
.el-header {
  background: #fff;
  box-shadow: 0 2px 8px #f0f1f2;
  padding: 0;
}
.el-main {
  padding: 2rem 0;
}
.el-card {
  min-height: 60vh;
  margin: 2rem auto;
  max-width: 900px;
}
</style> 