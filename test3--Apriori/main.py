import apriori

dataSet = apriori.loadDataSet()
L, supportData = apriori.apriori(dataSet, minSupport=0.1)

print "[result]-----------------------------------------"
rules = apriori.generateRules(L, supportData, minConf=0.5)