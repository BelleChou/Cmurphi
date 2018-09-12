## 用mutualData生成关联规则

由murphi获得的state 保存在mutual_data.csv中

-----------------------

在函数getTransList中转换数据

```python
for column in reader:
        if not transDict.has_key(column['id']):
            transDict[column['id']] = []
            if column['x'] == 'true':
                transDict[column['id']].append(0)
            elif column['x'] == 'false':
                transDict[column['id']].append(1)
        if column['n[1]'] == 'E':
            transDict[column['id']].append(2)
        elif column['n[1]'] == 'T':
            transDict[column['id']].append(3)
        elif column['n[1]'] == 'I':
            transDict[column['id']].append(4)
        elif column['n[1]'] == 'C':
            transDict[column['id']].append(5)

        if column['n[2]'] == 'E':
            transDict[column['id']].append(6)
        elif column['n[2]'] == 'T':
            transDict[column['id']].append(7)
        elif column['n[2]'] == 'I':
            transDict[column['id']].append(8)
        elif column['n[2]'] == 'C':
            transDict[column['id']].append(9)
return transDict
```

-----

run main.py (由于state数据很少，只有12条，而且多数不重复，所以最小支持度和最小置信度都取的很小)

------------------------



