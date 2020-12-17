import unittest

class RomanNumeralConverter(object):
    def __init__(self):
        self.digit_map = {"M":1000, "D":500, "C":100, "L":50, "X":10, "V":5, "I":1}
    
    def convert_to_decimal(self, roman_numeral):
        val = 0
        for char in roman_numeral:
            val += self.digit_map[char]
        return val

class RomanNumeralConverterTest(unittest.TestCase):
    def setUp(self):
        print "Creating a new RomanNumeralConverter..."
        self.cvt = RomanNumeralConverter()

    def tearDown(self):
        print "Destroying the RomanNumeralConverter..."
        self.cvt = None

    def test_parsing_millenia(self):
        self.assertEqual(11, self.cvt.convert_to_decimal("M"))

if __name__ == "__main__":
    unittest.main()