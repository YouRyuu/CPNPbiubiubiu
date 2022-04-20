class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> maxHeap; //大顶堆， 存储较小的那部分元素       
    priority_queue<int, vector<int>, greater<int>> minHeap;    //小顶堆，存储较大的那部分元素
    MedianFinder() {
        
    }
    void addNum(int num) {
        if(maxHeap.size()!=minHeap.size())
        {
            maxHeap.push(num);
            int v = maxHeap.top();
            maxHeap.pop();
            minHeap.push(v);
        }
        else
        {
            minHeap.push(num);
            int v = minHeap.top();
            minHeap.pop();
            maxHeap.push(v);
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size())
            return (1.0*(maxHeap.top() + minHeap.top())/2);
        else
            return 1.0*maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
