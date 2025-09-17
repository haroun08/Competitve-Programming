public class FoodRatings {


    private Dictionary<string, int> foodRatingMap;

    private Dictionary<string, string> foodCuisineMap;


    private Dictionary<string, SortedSet<(int rating, string food)>> cuisineFoodMap;

    public FoodRatings(IList<string> foods, IList<string> cuisines, IList<int> ratings)
    {
        foodRatingMap = new Dictionary<string, int>();
        foodCuisineMap = new Dictionary<string, string>();
        cuisineFoodMap = new Dictionary<string, SortedSet<(int rating, string food)>>();

        for (int i = 0; i < foods.Count; i++)
        {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodRatingMap[food] = rating;
            foodCuisineMap[food] = cuisine;

            if (!cuisineFoodMap.ContainsKey(cuisine))
            {
                cuisineFoodMap[cuisine] = new SortedSet<(int, string)>(new FoodComparer());
            }

            cuisineFoodMap[cuisine].Add((-rating, food));
        }
    }

    public void ChangeRating(string food, int newRating)
    {
        string cuisine = foodCuisineMap[food];
        int oldRating = foodRatingMap[food];


        cuisineFoodMap[cuisine].Remove((-oldRating, food));

        foodRatingMap[food] = newRating;

        cuisineFoodMap[cuisine].Add((-newRating, food));
    }

    public string HighestRated(string cuisine)
    {
        return cuisineFoodMap[cuisine].Min.food;
    }

    private class FoodComparer : IComparer<(int rating, string food)>
    {
        public int Compare((int rating, string food) x, (int rating, string food) y)
        {
            int cmp = x.rating.CompareTo(y.rating);
            if (cmp != 0) return cmp;

            return string.Compare(x.food, y.food, StringComparison.Ordinal);
        }
    }
}
