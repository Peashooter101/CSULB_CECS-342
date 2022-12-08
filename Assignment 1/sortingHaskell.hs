main :: IO()
main = do
    let x = [10, 2, 55, 891, 22, 1, -5]
    let y = [6,5,10,3,2,1]
    print (show x)
    print (show (qsort x))
    print (show (msort x))
    print (show y)
    print (show (qsort y))
    print (show (msort y))

qsort :: Ord a => [a] -> [a]
qsort [] = []
-- Filter all list elements based on the value of x.
-- then sort each side of the list element.
qsort (x:xs) = qsort (filter (< x) xs) ++ [x] ++ qsort (filter (>= x) xs)

msort :: Ord a => [a] -> [a]
msort [] = []
msort [x] = [x]
-- Keep splitting the list until you have individual pieces.
-- Final merge will look like merge [l] [r]
msort x = merge (msort l) (msort r) where
    -- Cut the list in half.
    (l, r) = splitAt (length x `div` 2) x

merge :: Ord a => [a] -> [a] -> [a]
merge x [] = x
merge [] y = y
-- Each sub-list will be sorted, so head will always be smallest.
-- Pull each head and compare, put the smaller head at the front of the list.
merge (x:xs) (y:ys) = if x < y then x : merge xs (y:ys) else y : merge (x:xs) ys