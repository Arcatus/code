solve :: Integer -> Integer -> Integer -> Integer
solve n m a = ((a - 1) `div` n) + 1 + b * m
    where b = (n - a) `mod` n

main = putStrLn . unwords . map show . (\(n:m:_:xs) -> map (solve n m) xs) . map read . words =<< getContents
