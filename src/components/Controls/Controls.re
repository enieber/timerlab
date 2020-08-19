open CssHelpers;

let button =
  Css.(
    style([
      noBorder,
      noOutline,
      padding(zero),
      background(transparent),
      cursor(pointer),
      selector("&:nth-child(2)", [marginLeft(1.->rem)]),
    ])
  );

let icon = isOpen =>
  Css.(
    style([
      //
      transform(`rotate(`deg(isOpen ? 0. : 180.))),
      transitionDuration(300),
    ])
  );

module TogglePlay = {
  [@react.component]
  let make = (~onPause, ~onPlay, ~color) => {
    let (state, setState) = React.useState(_ => false);

    <button
      onClick={_ => {
        setState(_ => !state);
        state ? onPause() : onPlay();
      }}
      className=button>
      {state ? <PauseIcon color /> : <PlayIcon color />}
    </button>;
  };
};

module Reset = {
  [@react.component]
  let make = (~onClick, ~color) => {
    <button onClick={_ => onClick()} className=button>
      <ResetIcon color />
    </button>;
  };
};

module ToggleSidebar = {
  [@react.component]
  let make = (~onClick, ~isOpen, ~color) => {
    <button onClick={_ => onClick()} className=button>
      <ToggleIcon color className={icon(isOpen)} />
    </button>;
  };
};
