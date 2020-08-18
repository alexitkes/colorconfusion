function twoDigitString (num) {
    if (num >= 0 && num < 10) {
        return "0" + num
    } else {
        return "" + num
    }
}

function getRandomColor () {
    var rnd = Math.floor(Math.random(1) * 6)

    return config.colorValues [rnd]
}

function getColorAlias (colorname) {
    var i

    for (i = 0; i < 6; i++) {
        if (colorname == config.colorValues [i]) {
            return config.colorAliases [i]
        }
    }

    return ""
}

function getTimerText (hundredths) {
    var num_hundredth = hundredths
    var num_sec = 0
    var num_min = 0

    num_min = Math.floor(hundredths / 6000)
    num_sec = Math.floor(hundredths / 100) % 60
    num_hundredth = hundredths % 100

    return (twoDigitString(num_min) + ":" + twoDigitString(num_sec) + ":" + twoDigitString(num_hundredth))
}

function getRandomArrangement () {
    var matrix = [Math.random(1), Math.random(1), Math.random(1), Math.random(1), Math.random(1), Math.random(1)]
    var arrangement = ["", "", "", "", "", ""]

    var i, j
    var count

    for (i = 0; i < 6; i++) {
        count = 0
        for (j = 0; j < 6; j++) {
            if (matrix [j] > matrix [i]) {
                count++
            }
        }

        if (arrangement [count] == "") {
            arrangement [count] = config.colorValues [i]
        } else {
            return (config.colorValues)
        }
    }

    return arrangement
}
