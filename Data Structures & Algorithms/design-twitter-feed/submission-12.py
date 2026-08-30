class Twitter:

    # assume every tweetId is unique
    # fetch at most the 10 most recent tweet IDs in the user's news feed
    # ordered from most recent to least recent, posted by users who the user follows
    
    # store list of followers
    # store list of most recent 10 posts by each person
    # getNewsFeed simply checks all lists


    def __init__(self):
        self.followLists = defaultdict(set)
        self.posts = []

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.posts.append([userId, tweetId])

    def getNewsFeed(self, userId: int) -> List[int]:
        candidates = set(self.followLists[userId])
        candidates.add(userId)
        res = []
        for i in range(len(self.posts) - 1, -1, -1):
            if self.posts[i][0] in candidates:
                res.append(self.posts[i][1])
                if len(res) == 10:
                    return res
        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        self.followLists[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.followLists[followerId].discard(followeeId)
