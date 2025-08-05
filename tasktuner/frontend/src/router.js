import { createRouter, createWebHistory } from 'vue-router';
import Home from './views/Home.vue';

const routes = [
  { path: '/', redirect: '/calendar' },
  {
    path: '/calendar',
    name: 'calendar',
    component: () => import('./views/TaskCalendar.vue')
  },
  {
    path: '/list',
    name: 'list',
    component: () => import('./views/TaskList.vue')
  },
  {
    path: '/timeline',
    name: 'timeline',
    component: () => import('./views/TaskTimeline.vue')
  },
  {
    path: '/stats',
    name: 'stats',
    component: () => import('./views/TaskStats.vue')
  },
  {
    path: '/note',
    name: 'note',
    component: () => import('./views/NoteEditor.vue')
  },
  {
    path: '/share',
    name: 'share',
    component: () => import('./views/NoteShare.vue')
  }
];

const router = createRouter({
  history: createWebHistory(),
  routes
});

// 添加导航守卫来调试路由问题
router.beforeEach((to, from, next) => {
  console.log('Navigation:', { from: from.path, to: to.path, toName: to.name });
  next();
});

export default router; 