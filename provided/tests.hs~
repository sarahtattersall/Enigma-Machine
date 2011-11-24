#!/usr/bin/env runghc
import Control.Applicative
import Control.Monad
import System.Directory
import System.Environment
import System.Exit
import System.IO
import System.Process

main :: IO ()
main = do
  args <- getArgs

  case args of
    [program] -> do checksOnProgram program
                    checksOnDirectory
                    runTests program
    _         -> do printHelpAndDie ""

printHelpAndDie msg = do
  putStrLn . unlines $ 
    [ "Usage: ./tests <path to enigma program>"
    , "  ensure that you run the testsuite in the testsuite directory"
    , msg
    ] 
  exitWith (ExitFailure 1)


checksOnProgram :: String -> IO ()
checksOnProgram program = do
  b1 <- doesFileExist program
  unless b1 $ printHelpAndDie (program ++ " does not exist")
  b2 <- executable <$> getPermissions program
  unless b2 $ printHelpAndDie (program ++ " is not executable")

checksOnDirectory :: IO ()
checksOnDirectory = do
  d1 <- doesDirectoryExist "./rotors"
  unless d1 $ printHelpAndDie ""


runTests program = do
  basicTests program
  mobyTests program

basicTests program = do
  putStrLn "Basic Tests"
  forM_ theBasicTests (runBasicTest program)
  putStrLn ""

theBasicTests = concatMap mkReverses $
  [ ("AAAAAAAAAAAAAAAAAAAAAAAAAA", ["plugboards/null.pb"], "NNNNNNNNNNNNNNNNNNNNNNNNNN")
  , ("AAAAAAAAAAAAAAAAAAAAAAAAAA", ["rotors/I.rot", "plugboards/I.pb"], "NNNNNNNNNNNNNNNNNNNNNNNNNN")
  , ("ZZZZZZZZZZZZZZZZZZZZZZZZZZ", ["rotors/I.rot", "plugboards/I.pb"], "VVVVVVVVVVVVVVVVVVVVVVVVVV")
  , ("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                                 , ["rotors/I.rot", "rotors/II.rot", "plugboards/null.pb"]
                                 , "LLLLLLLLLLLLLLLLLLLLLLLLLLPPPPPPPPPPPPPPPPPPPPPPPPPP")
  , ("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                                 , ["rotors/I.rot", "rotors/II.rot", "plugboards/IV.pb"]
                                 , "ZZZZZZZZZZZZZZZZZZZZZZZZZZXXXXXXXXXXXXXXXXXXXXXXXXXX")
  , ("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 , ["rotors/II.rot", "rotors/II.rot", "plugboards/null.pb"]
                                 , "NSPURWTYVAXCZEBGDIFKHMJOLQROTQVSXUZWBYDAFCHEJGLINKPM")
  , ("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 , ["rotors/II.rot", "rotors/II.rot", "plugboards/III.pb"]
                                 , "NQLWRUTCKVIYUEBGFXDKMJHRPSROPSVQIWGZBCQAFYMEHGNXLVTJ")
  ]

mkReverses (i, args, expRes) = [(i,args,expRes), (expRes, args, i)]

runBasicTest program (input, arguments, expResult) = do
  actResult <- filter (`elem` ['A'..'Z']) <$> readProcess program arguments input
  if (expResult == actResult)
    then putStr "."
    else do putStrLn ""
            putStrLn $ unlines [ "Arguments: " ++ unwords arguments
                               , show input ++ " ==> " ++ show actResult
                               , "Expected: " ++ show expResult
                               ] 

mobyTests program = do
  mobyText <- readProcess "gunzip" ["-c", "moby.txt.gz"] ""
  putStrLn "Harder Tests"
  forM_ theMobyTests (runMobyTest program mobyText)
  putStrLn ""


theMobyTests = [ (["rotors/III.rot", "rotors/VII.rot", "plugboards/II.pb"], "0315f65c4d79ad398a2c59ab638b81ba8fe34480bb8cce49cbe3908065c12527")
               , (["rotors/IV.rot",  "rotors/VI.rot", "rotors/II.rot", "plugboards/IV.pb"], "842e7c0f47b48dbe0f7e8aa54885043d7d0aaf19254f63c33c1d136a23b1cbb9")
               ]

runMobyTest program mobyText (arguments, expResult) = do
  actResult <- filter (`elem` ['A'..'Z']) <$> readProcess program arguments mobyText
  resultHash <- readProcess "sha256sum" [] actResult
  if (expResult ++ "  -\n" == resultHash) 
    then putStr "."
    else do putStrLn ""
            putStrLn $ unlines [ "Arguments: " ++ unwords arguments
                               , " gave an unexpected sha256sum hash: " ++ show resultHash ++ " expected: " ++ show expResult
                               ]
