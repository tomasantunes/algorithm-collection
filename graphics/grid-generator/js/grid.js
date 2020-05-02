$('#generate-btn').click(function() { generateGrid() });
$('#download-btn').click(function(e) { downloadImage(e) });

function downloadImage(e) {
	var btn = e.target;
	var c = document.getElementById('c');
	btn.href = c.toDataURL();
	btn.download = 'grid.png';
}
		
function generateGrid() {
	var c = document.getElementById('c');
	var ctx = c.getContext('2d');
	var color = $('#color-input').val();
	var w = Number($('#total-width-input').val());
	var h = Number($('#total-height-input').val());
	var cell_w = Number($('#cell-width-input').val());
	var cell_h = Number($('#cell-height-input').val());
	var cell_unit = $('#unit-select').val();
	
	c.width = w;
	c.height = h;
	
	if(cell_unit == 'percentage') {
		cell_w = (cell_w * w) / 100;
		cell_h = (cell_h * h) / 100;
	}
	
	ctx.clearRect(0,0,w,h);
	ctx.strokeStyle = color;
	
	for (var y = 0; y <= h; y += cell_h) {
		ctx.beginPath();
		ctx.moveTo(0,y);
		ctx.lineTo(w,y);
		ctx.stroke();
		ctx.closePath();
	}
	
	for (var x = 0; x <= w; x += cell_w) {
		ctx.beginPath();
		ctx.moveTo(x,0);
		ctx.lineTo(x,h);
		ctx.stroke();
		ctx.closePath();
	}
}