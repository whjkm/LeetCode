class MyHashMap:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.buckets = 1000                       # 键值块，哈希桶
        self.itemsPerBuckect = 1001               # 产生冲突的“拉链”块
        self.hashmap = [[] for _ in range(self.buckets)]        # _表示临时变量，仅用一次，后面无需用到

    # 散列函数
    def hash(self, key):
        return key % self.buckets                 # 取余

    # 处理冲突的函数
    def pos(self, key):
        return key // self.buckets                # 向下取整，返回商的整数部分

    def put(self, key, value):
        """
         value will always be positive.
         :type key: int
         :type value: int
         :rtype: void
        """
        hashkey = self.hash(key)
        if not self.hashmap[hashkey]:                 # 没有产生冲突，直接填入buckets中
            self.hashmap[hashkey] = [None] * self.itemsPerBuckect
        self.hashmap[hashkey][self.pos(key)] = value

    def get(self, key):
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        :type key: int
        :rtype: int
        """
        hashkey = self.hash(key)
        if(not self.hashmap[hashkey]) or self.hashmap[hashkey][self.pos(key)] == None:      # 没有找到这个值
            return -1
        else:
            return self.hashmap[hashkey][self.pos(key)]

    def remove(self, key):
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        :type key: int
        :rtype: void
        """
        hashkey = self.hash(key)
        if self.hashmap[hashkey]:
            self.hashmap[hashkey][self.pos(key)] = None


if __name__ == "__main__":
    hashmap = MyHashMap()
    hashmap.put(1, 1)
    hashmap.put(2, 2)
    hashmap.get(1)
    hashmap.get(3)
    hashmap.put(2, 1)
    hashmap.get(2)
    hashmap.remove(2)
    hashmap.get(2)









