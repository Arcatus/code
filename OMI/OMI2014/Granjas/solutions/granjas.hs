import Control.Monad.ST
import Data.Array.ST

visitStuff i a v = do
    visited <- readArray v i
    next <- readArray a i
    writeArray v i True
    if visited then return 0 else visitStuff next a v

solve (n:xs) = do
    a <- newListArray (1,n) xs
    v <- newArray (1,n) False
    visitStuff 1 a v

main = print . runST . solve . (map read :: [String] -> [Int]) . words =<< getContents
