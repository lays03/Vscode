# git pull
1、将远程指定分支 拉取到 本地指定分支上：
```javascript
git pull origin <远程分支名>:<本地分支名>
```
（注：命令里的尖括号<>只是包裹中文的标识，方便你看的，实际使用时不用写，不过冒号需要）

2、将远程指定分支 拉取到 本地当前分支上：
```javascript origin
git pull origin <远程分支名>
```
在克隆远程项目的时候，本地分支会自动与远程仓库建立追踪关系，可以使用默认的origin来替代远程仓库名

# git push
1、将本地当前分支 推送到 远程指定分支上（注意：pull是远程在前本地在后，push相反）：
```javascript
git push origin <本地分支名>:<远程分支名>
```
2、将本地当前分支 推送到 与本地当前分支同名的远程分支上（注意：pull是远程在前本地在后，push相反）：
```javascript
git push origin <本地分支名>
```

将本地分支与远程同名分支相关联
```javascript
git push -u origin <本地分支名>
```