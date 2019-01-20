// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {

    private List<Integer> list_;
    private int head_, size_;

	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.

        list_ = new ArrayList<Integer>();
        while (iterator.hasNext()) {
            list_.add(iterator.next());
        }

        head_ = 0;
        size_ = list_.size();
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        return list_.get(head_);
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
        return list_.get(head_++);
	}

	@Override
	public boolean hasNext() {
	    return (head_ < size_);
	}
}