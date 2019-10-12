# Log of Project
`记录了该项目的有意义或具有代表性的更改日志，用于进行追溯和重复解决相似问题` </br>

## 2019.10.12
为了解决每次在Designer中更改了UI设计之后，ui_\*.h并没有同步编译更新的问题，选择了对项目架构影响最小的一种方法： </br>
在文件[CGLab_DS.pro](./CGLab_DS/CGLab_DS.pro)中增加了`UI_DIR=../CGLab_DS`(line 2)，之后重新生成整个项目，就可以在修改了UI之后编译时，自动编译更新ui_\*.h文件于CGLab_DS中，与普通代码文件位于同一位置。 </br>
参考链接：[reference](https://www.itread01.com/content/1549550889.html)