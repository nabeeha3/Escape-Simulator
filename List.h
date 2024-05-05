#ifndef LIST_H
#define LIST_H

template <typename T>
class List
{
  class Node
  {
    public:
      T* data;
      Node* next;
  };

  public:
    List();
    ~List();
    List& operator+=(T);
    void convertToArray(T* arr, int& size);

  private:
    Node* head;
};

#endif

