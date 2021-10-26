package orderbook

import (
	"fmt"
	"sort"
)

type Orderbook struct {
	Ask []*Order
	Bid []*Order
}

func New() *Orderbook {
	// TODO
	return &Orderbook{}
}

func (orderbook *Orderbook) Match(order *Order) ([]*Trade, *Order) {

	return orderbook.Trade(order)
}

func (orderbook *Orderbook) Trade(order *Order) ([]*Trade, *Order) {
	var tradeArr []*Trade
	var propArr *[]*Order

	switch order.Side {
	case SideAsk:
		propArr = &orderbook.Bid
	case SideBid:
		propArr = &orderbook.Ask
	}

	for order.Volume != 0 {
		if len(*propArr) == 0 {
			orderbook.RejectOrder(order)
			break
		}

		theBestProp := (*propArr)[0]

		if propAccepted(order, theBestProp, 0) {
			var tradeValue uint64
			if order.Volume < theBestProp.Volume {
				tradeValue = order.Volume
			} else {
				tradeValue = theBestProp.Volume
			}

			trade := Trade{theBestProp, order, tradeValue, theBestProp.Price}
			order.Volume -= tradeValue
			theBestProp.Volume -= tradeValue
			tradeArr = append(tradeArr, &trade)

			if theBestProp.Volume == 0 {
				*propArr = (*propArr)[1:]
			}
		} else {
			orderbook.RejectOrder(order)
			break
		}
	}

	if order.Volume > 0 && order.Kind == KindMarket {
		return tradeArr, order
	}

	return tradeArr, nil
}

func propAccepted(order *Order, prop *Order, side int) bool {
	switch order.Kind {
	case KindMarket:
		return true
	case KindLimit:
		switch order.Side {
		case SideAsk:
			return order.Price <= prop.Price
		case SideBid:
			return order.Price >= prop.Price
		}
	}

	fmt.Println("Inaccessible point was accessed")
	return false
}

func (orderbook *Orderbook) RejectOrder(order *Order) {
	switch order.Side {
	case SideAsk:
		orderbook.Ask = append(orderbook.Ask, order)
		sort.Slice(orderbook.Ask, func(i, j int) bool {
			return orderbook.Ask[i].Price < orderbook.Ask[j].Price
		})
	case SideBid:
		orderbook.Bid = append(orderbook.Bid, order)
		sort.Slice(orderbook.Bid, func(i, j int) bool {
			return orderbook.Bid[i].Price > orderbook.Bid[j].Price
		})
	}
}
