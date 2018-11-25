from matplotlib import pyplot as plt
import math
# label-vertex
with open('./pyplot/label-vertex.txt', mode='rt') as f:
    l=[]
    n=[]
    while True:
        text=f.readline()
        if not text:
            break
        text=text.split()
        l=l+[text[0]]
        n=n+[int(text[1])]
    if len(l)!=0:
        plt.figure(1)
        plt.bar(l,n)
        plt.xlabel('label')
        plt.ylabel('# of vertex')
        plt.title('label-vertex')
        fig = plt.gcf()
        fig.savefig("./pyplot/%d_label-vertex.png", dpi=300)
        for i in range(len(n)):
            if n[i]!=0:
                n[i]=math.log(n[i])
        plt.figure(2)
        plt.bar(l,n)
        plt.xlabel('label')
        plt.ylabel('log(# of vertex)')
        plt.title('label-vertex')
        fig = plt.gcf()
        fig.savefig("./pyplot/%d_label-vertex_log.png", dpi=300)
# degree
with open('./pyplot/degree.txt', mode='rt') as f:
    while True:
        text=f.readline()
        if not text:
            break
        a=text.split()
        for i in range(len(a)):
            a[i]=int(a[i])

        b=[]
        for i in range(a[-1]+1):
            b.append(0)
    
        degree = list(range(0, a[-1]+1))
        for i in range(len(a)):
            b[a[i]]=b[a[i]]+1
    
        plt.figure(3)
        plt.bar(degree, b)
        plt.xlabel('degree')
        plt.ylabel('# of vertex')
        plt.title('degree')
        fig = plt.gcf()
        fig.savefig("./pyplot/%d_degree.png", dpi=300)
        for i in range(len(degree)):
            if degree[i]!=0:
                degree[i]=math.log(degree[i])
            if b[i]!=0:
                b[i]=math.log(b[i])
        plt.figure(4)
        plt.bar(degree, b, width=0.1)
        plt.xlabel('log(degree)')
        plt.ylabel('log(# of vertex)')
        plt.title('degree_log')
        fig = plt.gcf()
        fig.savefig("./pyplot/%d_degree_log.png", dpi=300)

# indegree
with open('./pyplot/indegree.txt', mode='rt') as f:
    while True:
        text=f.readline()
        if not text:
            break
        a=text.split()
        for i in range(len(a)):
            a[i]=int(a[i])
  
        b=[]
        for i in range(a[-1]+1):
            b.append(0)    
        degree = list(range(0, a[-1]+1))
        for i in range(len(a)):
            b[a[i]]=b[a[i]]+1
   
        plt.figure(5)
        plt.bar(degree, b)
        plt.xlabel('indegree')
        plt.ylabel('# of vertex')
        plt.title('indegree')
        fig = plt.gcf()
        fig.savefig("./pyplot/%d_indegree.png", dpi=300)
        for i in range(len(degree)):
            if degree[i]!=0:
                degree[i]=math.log(degree[i])
            if b[i]!=0:
                b[i]=math.log(b[i])
        plt.figure(6)
        plt.bar(degree, b, width=0.1)
        plt.xlabel('log(indegree)')
        plt.ylabel('log(# of vertex)')
        plt.title('indegree_log')
        fig = plt.gcf()
        fig.savefig("./pyplot/%d_indegree_log.png", dpi=300)
# outdegree
with open('./pyplot/outdegree.txt', mode='rt') as f:
    while True:
        text=f.readline()
        if not text:
            break
        a=text.split()
        for i in range(len(a)):
            a[i]=int(a[i])

        b=[]    
        for i in range(a[-1]+1):
            b.append(0)    
        degree = list(range(0, a[-1]+1))
        for i in range(len(a)):
            b[a[i]]=b[a[i]]+1
    
        plt.figure(7)
        plt.bar(degree, b)
        plt.xlabel('outdegree')
        plt.ylabel('# of vertex')
        plt.title('outdegree')
        fig = plt.gcf()
        fig.savefig("./pyplot/%d_outdegree.png", dpi=300)
        for i in range(len(degree)):
            if degree[i]!=0:
                degree[i]=math.log(degree[i])
            if b[i]!=0:
                b[i]=math.log(b[i])
        plt.figure(8)
        plt.bar(degree, b, width=0.1)
        plt.xlabel('log(outdegree)')
        plt.ylabel('log(# of vertex)')
        plt.title('degree_log')
        fig = plt.gcf()
        fig.savefig("./pyplot/%d_outdegree_log.png", dpi=300)
