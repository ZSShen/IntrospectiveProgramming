class Tweet {
    int tweetId;
    int time;

    public Tweet(int tweetId, int time) {
        this.tweetId = tweetId;
        this.time = time;
    }
}


class TweetComparator implements Comparator<Tweet> {

    public int compare(Tweet lhs, Tweet rhs) {
        if (lhs.time == rhs.time) {
            return 0;
        }
        if (lhs.time < rhs.time) {
            return 1;
        }
        return -1;
    }
}


class User {

    private Set<Integer> followees_;
    private List<Tweet> tweets_;

    public User() {
        followees_ = new HashSet<Integer>();
        tweets_ = new ArrayList<Tweet>();
    }

    public void addFollowee(int followeeId) {
        followees_.add(followeeId);
    }

    public void addTweet(int tweetId, int time) {
        tweets_.add(new Tweet(tweetId, time));
    }

    public void removeFollowee(int followeeId) {
        followees_.remove(followeeId);
    }

    public Set<Integer> getAllFollowees() {
        return followees_;
    }

    public List<Tweet> getAllTweets() {
        return tweets_;
    }
}


class Twitter {

    private int time_;
    private Map<Integer, User> users_;

    /** Initialize your data structure here. */
    public Twitter() {
        time_ = 0;
        users_ = new HashMap<Integer, User>();
    }

    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {

        User user = users_.get(userId);
        if (user == null) {
            user = new User();
            users_.put(userId, user);
        }

        user.addTweet(tweetId, time_++);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {

        User user = users_.get(userId);
        if (user == null) {
            return new ArrayList<Integer>();
        }

        PriorityQueue<Tweet> queue =
            new PriorityQueue<Tweet>(new TweetComparator());

        for (Tweet tweet : user.getAllTweets()) {
            queue.add(tweet);
        }

        for (int followeeId : user.getAllFollowees()) {
            User followee = users_.get(followeeId);
            for (Tweet tweet : followee.getAllTweets()) {
                queue.add(tweet);
            }
        }

        List<Integer> list = new ArrayList<Integer>();
        int count = 0;
        int limit = 10;

        while (queue.size() > 0) {
            Tweet tweet = queue.poll();
            list.add(tweet.tweetId);

            ++count;
            if (count == limit) {
                break;
            }
        }

        return list;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {

        User follower = users_.get(followerId);
        if (follower == null) {
            follower = new User();
            users_.put(followerId, follower);
        }

        User followee = users_.get(followeeId);
        if (followee == null) {
            users_.put(followeeId, new User());
        }

        if (followerId != followeeId) {
            follower.addFollowee(followeeId);
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {

        User follower = users_.get(followerId);
        if (follower == null) {
            follower = new User();
            users_.put(followerId, follower);
        }

        User followee = users_.get(followeeId);
        if (followee == null) {
            users_.put(followeeId, new User());
        }

        follower.removeFollowee(followeeId);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
