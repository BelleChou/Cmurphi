import apriori

dataSet = apriori.loadDataSet()
L, supportData = apriori.apriori(dataSet, minSupport=0.3)

rules = apriori.generateRules(L, supportData, minConf=0.7)