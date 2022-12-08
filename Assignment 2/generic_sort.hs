import Data.List

data Person = Person String Int

name :: Person -> String
name (Person n _) = n

age :: Person -> Int
age (Person _ a) = a

instance Show Person where
    show (Person n a) = n ++ " (" ++ show a ++ ")"

sortByAge :: Person -> Person -> Ordering
sortByAge (Person n1 a1) (Person n2 a2) =
    if a1 == a2 then compare n1 n2
    else compare a2 a1

main :: IO()
main = do
    let numbers = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25]
    let people = [
            Person "Hal" 20,
            Person "Susann" 31,
            Person "Dwight" 19,
            Person "Kassandra" 21,
            Person "Lawrence" 25,
            Person "Cindy" 22,
            Person "Cory" 27,
            Person "Mac" 19,
            Person "Romana" 27,
            Person "Doretha" 32,
            Person "Danna" 20,
            Person "Zara" 23,
            Person "Rosalyn" 26,
            Person "Risa" 24,
            Person "Benny" 28,
            Person "Juan" 33,
            Person "Natalie" 25
            ]
    let numbersSorted = sort numbers
    let peopleSortedName = sortBy (\(Person a _) (Person b _) -> compare a b) people
    let peopleSortedAge = sortBy sortByAge people

    putStrLn("Numbers:\n\t" ++ show numbers)
    putStrLn("People:\n\t" ++ show people)
    putStrLn("Numbers Sorted:\n\t" ++ show numbersSorted)
    putStrLn("People Sorted By Name:\n\t" ++ show peopleSortedName)
    putStrLn("People Sorted By Age (Descending):\n\t" ++ show peopleSortedAge)
