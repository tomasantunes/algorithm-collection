function DRSGrid(obj) {
	var t = this;
	t.rects = [];
	t.element = obj.element || 'body';
	t.min_size_behaviour = obj.minSizeBehaviour || 'freeze';
	t.w = $(t.element).width();
	t.h = $(t.element).height();
	t.pull = obj.pull;
	t.min_width = obj.minWidth || 30;
	t.min_height = obj.minHeight || 30;
	t.border_top;
	t.border_right;
	t.border_bottom;
	t.border_left;
	t.borders_x;
	t.border_y;
	
	t.getBordersX = function() {
		return t.border_left + t.border_right;
	}
	
	t.getBordersY = function() {
		return t.border_top + t.border_bottom;
	}

	t.Rectangle = function(x, y, w, h, p) {
		var r = this;
		r.x = x;
		r.y = y;
		r.w = w;
		r.h = h;
		r.position = p;
		r.hidden = false;
		
		r.getTL = function() {
			return {x: r.x, y: r.y};
		}
		r.getTR = function() {
			return {x: r.x + r.w, y: r.y};
		}
		r.getBL = function() {
			return {x: r.x, y: r.y + r.h};
		}
		r.getBR = function() {
			return {x: r.x + r.w, y: r.y + r.h};
		}
	}

	t.updateHandler = function(e) {
		$('.drs-grid-main').children().each(function(i, val) {
			if (val != e.target) {
				var elA = e.target;
				var elB = val;

				var rectA_index = elA.id.substring(14);
				var rectB_index = elB.id.substring(14);
				
				var rectA = new t.Rectangle(
					parseInt(elA.style.left, 10),
					parseInt(elA.style.top, 10),
					parseInt(elA.style.width, 10),
					parseInt(elA.style.height, 10),
					rectA_index
				);
				
				var rectB = new t.Rectangle(
					parseInt(elB.style.left, 10),
					parseInt(elB.style.top, 10),
					parseInt(elB.style.width, 10),
					parseInt(elB.style.height, 10),
					rectB_index
				);

				t.rects[rectA_index] = rectA;
				t.rects[rectB_index] = rectB;
				

				t.collide(rectA, rectB);
				
				elB.style.left = rectB.x +'px';
				elB.style.top = rectB.y +'px';
				elB.style.width = rectB.w +'px';
				elB.style.height = rectB.h +'px';
				
				elA.style.left = rectA.x +'px';
				elA.style.top = rectA.y +'px';
				elA.style.width = rectA.w +'px';
				elA.style.height = rectA.h +'px';

				$.each(t.rects, function(i2, val2) {
					if (val2 != rectA) {
						var el = document.getElementById('drs-grid-child' + i2);
						t.collide(rectB, val2);
						el.style.left = val2.x +'px';
						el.style.top = val2.y +'px';
						el.style.width = val2.w +'px';
						el.style.height = val2.h +'px';
					}
				});

			}
		});
	}

	t.collide = function(rectA, rectB) {
		var aer = t.getEdgeRects(rectA);
		var ber = t.getEdgeRects(rectB);

		if (t.pointInRect(rectB.getTL(), aer.bottom) || t.pointInRect(rectB.getTR(), aer.bottom) || t.pointInRect(rectA.getBR(), ber.top) || t.pointInRect(rectA.getBL(), ber.top)) {

			var bb = rectB.getBL().y;
			var bt = rectB.getTL().y;
			var bh = rectB.h;
			var is_pull = false;
			
			rectB.y = rectA.getBL().y + t.getBordersY();
			rectB.h = bb - rectA.getBL().y - t.getBordersY();
			
			if(rectB.y < bt) {
				is_pull = true;
			}
			
			if(t.checkMinHeight(rectB)) {
				if (t.min_size_behaviour == 'freeze') {
					rectB.y = bt;
					rectB.h = bh;
					rectA.h = bt - rectA.y;
				}
				else if (t.min_size_behaviour == 'destroy') {
					t.rects[rectB.position] = new t.Rectangle(-999, -999, -999, -999, rectB.position);
					t.rects[rectB.position].hidden = true;
				}
			}
			
			if (is_pull && !t.pull) {
				rectB.y = bt;
				rectB.h = bh;
			}
		}
		if (t.pointInRect(rectB.getTL(), aer.right) || t.pointInRect(rectB.getBL(), aer.right) || t.pointInRect(rectA.getTR(), ber.left) || t.pointInRect(rectA.getBR(), ber.left)) {

			var br = rectB.getTR().x;
			var bl = rectB.getTL().x
			var bw = rectB.w;
			var is_pull = false;

			rectB.x = rectA.getTR().x + t.getBordersX();
			rectB.w = br - rectA.getTR().x - t.getBordersX();
			
			if (rectB.x < bl) {
				is_pull = true;
			}
			
			if(t.checkMinWidth(rectB)) {
				if (t.min_size_behaviour == 'freeze') {
					rectB.x = bl;
					rectB.w = bw;
					rectA.w = bl - rectA.x;
				}
				else if (t.min_size_behaviour == 'destroy') {
					t.rects[rectB.position] = new t.Rectangle(-999, -999, -999, -999, rectB.position);
					t.rects[rectB.position].hidden = true;
				}
			}
			if (is_pull && !t.pull) {
				rectB.x = bl;
				rectB.w = bw;
			}
			
		}
		if (t.pointInRect(rectB.getBL(), aer.top) || t.pointInRect(rectB.getBR(), aer.top) || t.pointInRect(rectA.getTR(), ber.bottom) || t.pointInRect(rectA.getTL, ber.bottom)) {

			var bh = rectB.h;
			var is_pull = false;
			
			rectB.h = rectA.getTL().y - rectB.y - t.getBordersY();
			
			if (rectB.h > bh) {
				is_pull = true;
			}
			
			if(t.checkMinHeight(rectB)) {
				if (t.min_size_behaviour == 'freeze') {
					rectB.h = bh;
					rectA.y = rectB.y + bh;
				}
				else if (t.min_size_behaviour == 'destroy') {
					t.rects[rectB.position] = new t.Rectangle(-999, -999, -999, -999, rectB.position);
					t.rects[rectB.position].hidden = true;
				}
			}
			if (is_pull && !t.pull) {
				rectB.h = bh;
			}
		}
		if (t.pointInRect(rectB.getBR(), aer.left) || t.pointInRect(rectB.getTR(), aer.left) || t.pointInRect(rectA.getTL(), ber.right) || t.pointInRect(rectA.getBL(), ber.right)) {

			var bw = rectB.w;
			var is_pull = false;
			
			rectB.w = rectA.getTL().x - rectB.x - t.getBordersX();
			
			if (rectB.w > bw) {
				is_pull = true;
			}

			if(t.checkMinWidth(rectB)) {
				if (t.min_size_behaviour == 'freeze') {
					rectB.w = bw;
					rectA.x = rectB.x + bw;
				}
				else if (t.min_size_behaviour == 'destroy') {
					t.rects[rectB.position] = new t.Rectangle(-999, -999, -999, -999, rectB.position);
					t.rects[rectB.position].hidden = true;
				}
			}
			if (is_pull && !t.pull) {
				rectB.w = bw;
			}
		}
	}

	t.checkMinWidth = function(a) {
		return a.w < t.min_width;
	}

	t.checkMinHeight = function(a) {
		return a.h < t.min_height;
	}

	t.getEdgeRects = function(a) {
	  	var rects = {
	  		top: { top: a.getTL().y - 40, left: a.getTL().x - t.border_left, width: a.getTR().x - a.getTL().x + t.border_right, height: 80 },
	  		right: { top: a.getTR().y - t.border_top, left: a.getTR().x - 40, width: 80, height: a.getBR().y - a.getTR().y + t.border_bottom },
	  		bottom: { top: a.getBL().y - 40, left: a.getBL().x - t.border_left, width: a.getBR().x - a.getBL().x + t.border_right, height: 80 },
	  		left: { top: a.getTL().y - t.border_top, left: a.getTL().x - 40, width: 80, height: a.getBL().y - a.getTL().y + t.border_bottom },
	  	}
	  	return rects;
	};

	t.pointInRect = function(point, rect) {
		if(point.x > rect.left && point.x < rect.left + rect.width && point.y > rect.top && point.y < rect.top + rect.height) {
			return true;
		}
		else {
			return false;
		}
	}

	t.getInfo = function() {
		var info = [];
		$.each(t.rects, function(i, val) {
			if(val.hidden == false) {
				val['id'] = 'drs-grid-child' + val.position;
				info.push(val);
			}
		});
		$.each(info, function(i, val) {
			delete val.hidden;
		});
		return info;
	};

	t.init = function() {
		$.each(obj.rects, function(i, val) {
			t.rects.push(new t.Rectangle(val[0], val[1], val[2], val[3], i));
		});

		$(t.element).append('<div class="drs-grid-main"></div>');

		t.w -= parseInt($('.drs-grid-main').css('border-left-width'), 10) + parseInt($('.drs-grid-main').css('border-right-width'), 10);
		t.h -= parseInt($('.drs-grid-main').css('border-top-width'), 10) + parseInt($('.drs-grid-main').css('border-bottom-width'), 10);

		$('.drs-grid-main').remove();

		$(t.element).append('<div class="drs-grid-main" style="width: '+ t.w +'px; height: '+ t.h +'px;"></div>')

		$.each(t.rects, function(i, val) {
			val.x = (val.x * t.w) / 100; 
			val.y = (val.y * t.h) / 100; 
			val.w = (val.w * t.w) / 100; 
			val.h = (val.h * t.h) / 100; 
			$('.drs-grid-main').append('<div id="drs-grid-child'+ i +'" class="drs-grid-child" style="left: '+ val.x +'px; top: '+ val.y +'px; width: '+ val.w +'px; height: '+ val.h +'px;"></div>');
		});


		$.each(t.rects, function(i, val) {
			var el = document.getElementById('drs-grid-child' + i);
			t.border_top = parseInt($(el).css('border-top-width'), 10);
			t.border_right = parseInt($(el).css('border-right-width'), 10);
			t.border_bottom = parseInt($(el).css('border-bottom-width'), 10);
			t.border_left = parseInt($(el).css('border-left-width'), 10);
			t.borders_x = t.getBordersX();
			t.borders_y = t.getBordersY();
			val.w -= t.borders_x;
			val.h -= t.borders_y;
		});

		$('.drs-grid-main').empty();


		$.each(t.rects, function(i, val) {
			$('.drs-grid-main').append('<div id="drs-grid-child'+ i +'" class="drs-grid-child" style="left: '+ val.x +'px; top: '+ val.y +'px; width: '+ val.w +'px; height: '+ val.h +'px;"></div>');
		});

		$('.drs-grid-child').resizable({
		  containment: "parent",
		});
		$('.drs-grid-child').draggable({
		  containment: "parent",
		});
		
		$('.drs-grid-child').css('min-width', t.min_width + 'px');
		$('.drs-grid-child').css('min-height', t.min_height + 'px');

		$('.drs-grid-main').on('resize', t.updateHandler);
		$('.drs-grid-main').on('drag', t.updateHandler);
	};

	t.init();
}