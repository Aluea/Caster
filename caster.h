#ifndef __CASTER__
#define __CASTER__
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<life.h>
#include<m_map.h>
#include<affairs.h>
//#include<database.h>
#define INF 1<<30

struct pic{
    int x,y,z,w,h;
    int id_pic,idarea;
    int type;//0人1图
    bool m_exit,is_new;
};

struct showturn{
    int z;
    int id;
    int pic;
};
bool cmp(showturn a,showturn b);

#endif
