// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : Siyuan Xu
// Date   : 2015-08-06

/********************************************************************************** 
* 
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
* 
*               
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //priority queue 
 //432ms
class Solution0 {
public:
	struct compare {
		bool operator() (ListNode* l1, ListNode* l2) {
			return (l1->val > l2->val);
		}
	};
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* head = NULL;
		ListNode** it = &head;
		priority_queue<ListNode*, vector<ListNode*>, compare> q;
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i]) q.push(lists[i]);
		}
		while (!q.empty()) {
			*it = q.top();
			q.pop();
			if ((*it)->next) {
				q.push((*it)->next);
			}
			it = &((*it)->next);
		}
		return head;
	}
};
 
 //priority queue 
 //432ms
class Solution1 {

public:

    // custom comparator used to compare between two listNode pointers. 
    // note : all pointers to be compared is supposed to be valid pointers.
    struct comparator
    {
        bool operator() ( ListNode* i, ListNode* j)
         {
            return i->val > j->val;
         }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {

       // shortcut for edge cases. 
       if (lists.size() == 0) return NULL;
       if (lists.size() == 1) return lists[0]; 

       // initialize the maxHeap. 
       priority_queue<ListNode*, std::vector<ListNode*>, comparator> maxHeap;

       // push the head of each of the items in list. 
       for (int i = 0; i< lists.size(); i++)
       {
           if (lists[i]!= NULL) maxHeap.push(lists[i]);
       }

       // shortcut if we failed to find even one valid list. 
       if (maxHeap.size() == 0) return NULL;

       // build the empty node as the return pointer.
       ListNode returnVal = ListNode(-1), *tmp = &returnVal; 

       // loop until the heap is empty. 
       while (maxHeap.size() >0)
       {
           tmp->next = maxHeap.top();
           maxHeap.pop();
           tmp = tmp->next;
           if (tmp->next != NULL && maxHeap.size()!=0)
           {
               maxHeap.push(tmp->next);
           }
       }

       return returnVal.next;
    }
};

//custom heap
class Solution2 {
    private:

    // Predicate to remove all null nodes from a vector:
    static bool isNull(const ListNode* a) {

        return a == nullptr;
    }

    // Predicate to generate a min heap of list node pointers:
    static bool minHeapPred(const ListNode* a,
                            const ListNode* b) {

        assert(a);
        assert(b);

        return a->val > b->val;
    }
public:
struct compare {
		bool operator() (ListNode* l1, ListNode* l2) {
			return (l1->val > l2->val);
		}
	};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Begin and end of our range of elements:
        auto it_begin = begin(lists);
        auto it_end = end(lists);

        // Removes empty lists:
        it_end = remove_if(it_begin, it_end, isNull);
        if (it_begin == it_end) return nullptr; // All lists where empty.

        // Head and tail of the merged list:
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        // Builds a min-heap over the list of lists:
        make_heap(it_begin, it_end, minHeapPred);

        // The first element in the heap is the head of our merged list:
        head = tail = *it_begin;

        while (distance(it_begin, it_end) > 1) {

            // Moves the heap's front list to its back:
            pop_heap(it_begin, it_end, minHeapPred);

            // And removes one node from it:
            --it_end;
            *it_end = (*it_end)->next;

            // If it is not empty it inserts it back into the heap:
            if (*it_end) {

                ++it_end;
                push_heap(it_begin, it_end, minHeapPred);
            }

            // After  the push we have our next node in front of the heap:
            tail->next = *it_begin;
            tail = tail->next;
        }

        return head;
        
    }
};
