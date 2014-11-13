-- script.lua
item = "test"
items = {
    test = "fail",
    {
       itemName = "sword",
       dropChance = 80
    },
    {
        itemName = "ruby",
        dropChance = 10
    }
}

sum = function(a, b) 
    return a + b
end

u = {
    one = {
        one = {
            a = "a",
            b = "b"
        },
        two = {
            c = "c",
            d = "d"
        }
    },
    two = {
        one = {
            e = "e",
            f = "f"
        },
        two = {
            g = "g",
            h = "h"
        }
    }
}

printChoices("Would you like to...", {"YES", "NO", "MAYBE"})