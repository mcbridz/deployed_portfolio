var canvas = document.querySelector('#main_canvas')
canvas.width = window.innerWidth
canvas.height = window.innerHeight


var c = canvas.getContext('2d')

// co => canvas context, blX => bottom-left X coor, blY => bottom-left Y coor
const drawKeyboardDesk = (co, blX, blY, baseWidth) => {
    // front of keyboard
    co.beginPath()
    co.moveTo(blX, blY)
    co.lineTo(blX + baseWidth, blY)
    co.lineTo(blX + baseWidth, blY + 5)
    co.lineTo(blX, blY + 5)
    co.lineTo(blX, blY)
    co.stroke()

    // data calculations from input
    let topWidth = parseInt(baseWidth * 0.85)
    let topEdgeDelta = parseInt((baseWidth - topWidth) / 2)
    let height = parseInt(baseWidth / 10)

    // back edge of keyboard
    co.moveTo(blX + topEdgeDelta, blY - height)
    co.lineTo((blX + topEdgeDelta + topWidth), blY - height)
    co.stroke()

    // coordinate pair array of objects
    // example obj = { x: 0, y: 0}
    let bottomKeyLines = [], topKeyLines = []

    // space between keys at bottom of keyboard
    let deltaX = parseInt((blX + baseWidth) / 20)

    // determine keyboard key lines by Reinmann method
    for (let x = blX, tX = blX + topEdgeDelta;
        x <= blX + baseWidth;
        x += deltaX, tX += parseInt(deltaX * 0.85)) {
        bottomKeyLines.push({ x: x, y: blY })
        topKeyLines.push({ x: tX, y: (blY - height)})
    }

    // right-side edge
    bottomKeyLines.push({ x: blX + baseWidth, y: blY })
    topKeyLines.push({ x: (blX + baseWidth - topEdgeDelta), y: blY - height })
    
    // console.log(bottomKeyLines)
    // console.log(topKeyLines)

    // draw vertical key lines
    for (let i = 0; i < bottomKeyLines.length; i++){
        co.beginPath()
        co.moveTo(bottomKeyLines[i].x, bottomKeyLines[i].y)
        co.lineTo(topKeyLines[i].x, topKeyLines[i].y)
        co.stroke()
    }

    // making utility functions
    const makeLinearFunction = (leftSidePoint, rightSidePoint) => {
        return (y) => {
            let m =  (rightSidePoint.y - leftSidePoint.y) / (rightSidePoint.x - leftSidePoint.x)
            // y=mx+b => b=y-mx
            let b = (leftSidePoint.y - (m * leftSidePoint.x))
            
            // x=(y-b)/m
            return Math.round(( y - b ) / m)
        }
    }
    const leftSideFunction = makeLinearFunction(
        { x: blX, y: blY },
        { x: blX + topEdgeDelta, y: blY - height })
    const rightSideFunction = makeLinearFunction(
        { x: blX + baseWidth - topEdgeDelta, y: blY - height },
        { x: blX + baseWidth, y: blY })    
    const heightDelta = Math.round(height / 4)
    

    // determine horizontal keylines
    let leftSidePoints = [], rightSidePoints = []
    let y = blY - heightDelta
    let tempDelta = heightDelta
    while(y >= blY - height) {
        leftSidePoints.push({ x: leftSideFunction(y), y: y })
        rightSidePoints.push({ x: rightSideFunction(y), y: y })
        y -= tempDelta
        tempDelta = parseInt(tempDelta * 0.85)
    }

    // draw keylines
    for (let i = 0; i < leftSidePoints.length; i++) {
        co.beginPath()
        co.moveTo(leftSidePoints[i].x, leftSidePoints[i].y)
        co.lineTo(rightSidePoints[i].x, rightSidePoints[i].y)
        co.stroke()
    }
}

console.log(drawKeyboardDesk(c, parseInt((window.innerWidth / 2) - 400), window.innerHeight - 100, 800))