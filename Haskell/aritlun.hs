module Main where

import Test.QuickCheck

suma :: Integer -> Integer -> Integer
suma 0 0 = 0
suma x y = max x2 y2 + 10 * suma x1 y1
  where (x1,x2) = x `divMod` 10
        (y1,y2) = y `divMod` 10
 
producto :: Integer -> Integer -> Integer
producto 0 _ = 0
producto x y = productoDigitoNumero x2 y `suma` (10 * producto x1 y)
  where (x1, x2) = x `divMod` 10

productoDigitoNumero :: Integer -> Integer -> Integer
productoDigitoNumero _ 0 = 0
productoDigitoNumero d x = min d x2 + 10 * productoDigitoNumero d x1
  where (x1, x2) = x `divMod` 10
 
prop_conmutativa :: Positive Integer -> Positive Integer -> Bool
prop_conmutativa (Positive x) (Positive y) =
  suma x y == suma y x &&
  producto x y == producto y x

main :: IO()

main = do

 input1 <- getLine
 input2 <- getLine
 let x = (read input1:: Integer )
 let y = (read input2:: Integer )
 print (producto x y)


