$.fn.blur = function(anim, time, cb) {
  if (time) this.css('-webkit-transition', time / 1000 + 's');

  this.addClass(anim);

  if ($.isFunction(cb)) {
    setTimeout(function() {
      $(this).each(cb);
    }, (time) ? time : 250);
  }
  return this;

};
