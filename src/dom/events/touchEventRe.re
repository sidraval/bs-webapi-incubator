type touchList; /* TODO, Touch Events */

module Impl (T: { type t; }) => {
  external altKey : T.t => bool = "" [@@bs.get];
  external changedTouches : T.t => touchList = "" [@@bs.get];
  external ctrlKey : T.t => bool = "" [@@bs.get];
  external metaKey : T.t => bool = "" [@@bs.get];
  external shiftKey : T.t => bool = "" [@@bs.get];
  external targetTouches : T.t => touchList = "" [@@bs.get];
  external touches : T.t => touchList = "" [@@bs.get];
};

type t = Dom.touchEvent;
include EventRe.Impl { type nonrec t = t };
include UiEventRe.Impl { type nonrec t = t };
include Impl { type nonrec t = t };

external make : string => t = "TouchEvent" [@@bs.new];
external makeWithOptions : string => Js.t {..} => t = "TouchEvent" [@@bs.new];
